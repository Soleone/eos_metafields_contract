#include <eosiolib/eosio.hpp>

using namespace eosio;

class metafields_contract : public contract {
  public:

    metafields_contract(account_name self) :
      contract(self),
      metafields(_self, _self)
      {}

    // @abi action
    void create(account_name owner, std::string& key, std::string& value) {
      metafields.emplace(owner, [&](auto& new_metafield) {
        new_metafield.id = metafields.available_primary_key();
        new_metafield.owner = owner;
        new_metafield.key = key;
        new_metafield.value = value;
      });

      print("[create] ", key, "=", value);
    }

    // @abi action
    void destroy(account_name owner, const uint64_t id) {
      auto metafield_to_delete = metafields.find(id);
      metafields.erase(metafield_to_delete);

      print("[destroy] id=", id);
    }

  private:
    // @abi table metafields i64
    struct metafield {
      uint64_t id;
      account_name owner;

      std::string key;
      std::string value;

      uint64_t primary_key() const { return id; }
      account_name by_owner() const { return owner; }

      EOSLIB_SERIALIZE(metafield, (id)(owner)(key)(value))
    };

    typedef multi_index<N(metafields), metafield> metafields_table;
    metafields_table metafields;
};

EOSIO_ABI(metafields_contract, (create)(destroy))
