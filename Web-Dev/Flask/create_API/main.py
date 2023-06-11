from flask import Flask, jsonify
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/check/<int:val>')
def is_int(val):
    if type(val) == int:
        result = {
            "Number": True,
            "YourInput": val,
            "Status": "Okay"
        }
    else:
        if val.is_integer():
            result = {
                "Number": True,
                "YourInput": val,
                "Status": "Okay"
            }
        else:
            result = {
                "Number": False,
                "YourInput": val,
                "Status": "Invalid Input"
            }
    return jsonify(result)
        
if __name__ == "__main__":
    app.run(debug = True)