import os
import sys
import urllib

import pytest

# Config
if sys.platform == "win32":
    PHANTOMJS_PATH = "tools/phantomjs/bin/phantomjs.exe"
else:
    PHANTOMJS_PATH = "phantomjs"
SITE_URL = "http://127.0.0.1:43110"

# Imports relative to src dir
sys.path.append(
    os.path.abspath(os.path.dirname(__file__)+"/..")
)
from Config import config
config.argv = ["none"]  # Dont pass any argv to config parser
config.parse()
config.data_dir = "src/Test/testdata"  # Use test data for unittests

from Site import Site
from User import UserManager

@pytest.fixture(scope="session")
def resetSettings(request):
    os.chdir(os.path.abspath(os.path.dirname(__file__)+"/../..")) # Set working dir
    open("%s/sites.json" % config.data_dir, "w").write("{}")
    open("%s/users.json" % config.data_dir, "w").write("""
        {
            "15E5rhcAUD69WbiYsYARh4YHJ4sLm2JEyc": {
                "certs": {},
                "master_seed": "024bceac1105483d66585d8a60eaf20aa8c3254b0f266e0d626ddb6114e2949a",
                "sites": {}
            }
        }
    """)
    def cleanup():
        os.unlink("%s/sites.json" % config.data_dir)
        os.unlink("%s/users.json" % config.data_dir)
    request.addfinalizer(cleanup)

@pytest.fixture(scope="session")
def site():
    site = Site("1TeSTvb4w2PWE81S2rEELgmX2GCCExQGT")
    return site


@pytest.fixture(scope="session")
def user():
    user = UserManager.user_manager.get()
    return user

@pytest.fixture(scope="session")
def browser():
    try:
        from selenium import webdriver
        browser = webdriver.PhantomJS(executable_path=PHANTOMJS_PATH, service_log_path=os.path.devnull)
        browser.set_window_size(1400, 1000)
    except Exception, err:
        raise pytest.skip("Test requires selenium + phantomjs: %s" % err)
    return browser

@pytest.fixture(scope="session")
def site_url():
    try:
        urllib.urlopen(SITE_URL).read()
    except Exception, err:
        raise pytest.skip("Test requires zeronet client running: %s" % err)
    return SITE_URL
