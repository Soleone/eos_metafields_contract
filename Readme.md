# Metafields

A simple EOS smart contract to store key value pairs for an account. The data is stored in the RAM of the caller of the smart contract.

An example use case is using it as an address book so that each EOS account can store an associated email address or URL that tools can then lookup and use to e.g. send notifications to the account owner.

## Usage

### Examples

##### Creating a new meta field for an account:

`cleos push action ACCOUNT_NAME create '{"owner": "ACCOUNT_NAME", "key": "email", "value": "sole@one.com"}' -p ACCOUNT_NAME@active`

##### Deleting an existing meta field by id:

`cleos push action ACCOUNT_NAME destroy '{"owner": "ACCOUNT_NAME", "id": 0}' -p ACCOUNT_NAME@active`

##### Listing an account's meta fields:

`cleos get table ACCOUNT_NAME ACCOUNT_NAME metafields`
