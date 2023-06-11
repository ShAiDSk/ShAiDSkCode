db.details.find() // Fetch all documents
db.details.find({class:"IX"}) // Fetch whose class IX

db.names.insertMany([{_id: 2, "name": "Leo"}, {_id: 4, "name": "neon"}])