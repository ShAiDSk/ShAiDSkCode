from flask import Flask
app = Flask(__name__)

@app.route("/")
def root():
    return "Hello User: <h1> ShaidSk! </h1>"

if __name__ == "__main__":
    app.run(debug=True)