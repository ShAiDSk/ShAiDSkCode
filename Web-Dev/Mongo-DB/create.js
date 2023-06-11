db.products.insertOne( { item: "Ball", qty: 1 } )
db.items.insertOne( { item: "pin", qty: 5 } )

db.products.insertMany(
    [
        { _id: 1, item: "pencil", qty: 50, type: "no.2" },
        { item: "pen", qty: 20 },
        { item: "eraser", qty: 25 },
        { _id: 2, item: "paper", qty: 50, type: "no.3" },
        { item: "bread", qty: 20 },
        { item: "biscuit", qty: 25 }
    ]
)

db.details.insertMany(
    [
        { _id: 1, name: "Lua", roll: "no. 1", class: "IX" },
        { _id: 2, name: "Leo", roll: "no. 2", class: "IX" },
        { _id: 3, name: "Shaid", roll: "no. 3", class: "IX" },
        { _id: 4, name: "Alisha", roll: "no. 4", class: "IX" },
        { _id: 5, name: "Harry", roll: "no. 5", class: "IX" }
    ]
)