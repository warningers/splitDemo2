/**
 *  @file
 *  @copyright defined in dmc/LICENSE.txt
 */

#include <dmc.token/dmc.token.hpp>

namespace eosio {

void token::receipt(extended_asset in, extended_asset out, extended_asset fee)
{
    require_auth(_self);
}

void token::outreceipt(name owner, extended_asset x, extended_asset y)
{
    require_auth(_self);
}

void token::traderecord(name owner, name oppo, extended_asset from, extended_asset to, extended_asset fee, uint64_t bid_id)
{
    require_auth(_self);
}

void token::orderchange(uint64_t bid_id, uint8_t state)
{
    require_auth(_self);
}

void token::bidrec(uint64_t price, extended_asset quantity, extended_asset filled, uint64_t bid_id)
{
    require_auth(_self);
}

void token::pricerec(uint64_t old_price, uint64_t new_price)
{
    require_auth(_self);
}

void token::uniswapsnap(name owner, extended_asset quantity)
{
    require_auth(_self);
    require_recipient(owner);
}

void token::billrec(name owner, extended_asset asset, uint64_t bill_id, uint8_t state)
{
    require_auth(_self);
}

void token::incentiverec(name owner, extended_asset inc, uint64_t bill_id, uint64_t order_id, uint8_t type)
{
    require_auth(_self);
}

void token::orderclarec(name owner, extended_asset quantity, uint64_t bill_id, uint64_t order_id)
{
    require_auth(_self);
}

void token::redeemrec(name owner, name miner, extended_asset asset)
{
    require_auth(_self);
}

void token::nftsymrec(uint64_t symbol_id, extended_symbol nft_symbol, std::string symbol_uri, nft_type type)
{
    require_auth(_self);
}

void token::nftrec(uint64_t symbol_id, uint64_t nft_id, std::string nft_uri, std::string nft_name, std::string extra_data, extended_asset quantity)
{
    require_auth(_self);
}

void token::nftaccrec(uint64_t family_id, uint64_t nft_id, name owner, extended_asset quantity)
{
    require_auth(_self);
}

void token::liqrec(name miner, extended_asset pst_asset, extended_asset dmc_asset)
{
    require_auth(_self);
}

void token::makerliqrec(name miner, uint64_t bill_id, extended_asset sub_pst)
{
    require_auth(_self);
}

void token::makercharec(name sender, name miner, extended_asset changed, MakerReceiptType type)
{
    require_auth(_self);
}

void token::ordercharec(uint64_t order_id, extended_asset storage, extended_asset lock, extended_asset settlement, extended_asset challenge, time_point_sec exec_date, OrderReceiptType type)
{
    require_auth(_self);
}

void token::assetcharec(name owner, extended_asset changed, uint8_t type, uint64_t order_id)
{
    require_auth(_self);
}

void token::orderrec(dmc_order order_info, uint8_t type)
{
    require_auth(_self);
}

void token::challengerec(dmc_challenge challenge_info)
{
    require_auth(_self);
}

} /// namespace eosio
