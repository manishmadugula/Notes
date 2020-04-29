# Types of NoSQL

### Note
- SQL is Row Oriented.

## Key Value Stores
- Key-Value stores store keys value pairs, generally in buckets, exactly like a hash table data structure...each key must be unique.
- They are extremely fast for writing, and extremely fast for reading and updating...if you have the key.
- They are slow on multiple updates and if you have to query the entire store.
- Used a lot in caching stores because of fast reads, like memcached, Raik, Redis.

## Column Oriented
- seem to store data in related rows, but they actually serialize the data into columns.
- This allows for much faster querying and processing of data while storing data that's somewhat related. searching on each column much faster.
- inserts and updates are generally slower in column databases.
-  Columnar databases are often an order of magnitude faster than row based databases for common reporting usage. 
-  Used in Online analytical processing. 
- These are used in a lot of high powered big-data analysis where speed is critical. (Cassandra, Google's BigTable, Druid)

## Row Oriented (SQL)
- row based in used in Online transaction processing.
- Row stores have the ability to write data very quickly, 

## Document Stores
- A document database is still basically a key-value store,
- store data in "documents", typically XML or JSON documents. 
- They're typically schemaless, so each document can contain any data that you want them to have and you can change it on the fly.
- Document stores allow you to play with your data and store it however you see fit.
- Some examples include: MongoDB, OrientDB, CouchDB, Azure's DocumentDB, AWS DynamoDB, RethinkDB.

## Graph Stores
- Graph databases are used to solve a problem that can be very difficult to solve with relational databases i.e complex mappings between data.
-  A database schema generally needs well defined relationships between tables, and complex many-to-many relationships could require a large number of junction tables which are complicated and may require expensive joins.
-  Graph databases can store complex and fluid relationships with ease. 
-  The trade-off is that querying or updating large amounts of data can be very slow,Since nodes of similar nodes that aren't necessarily related are usually not stored close together.

