from flask import Flask, redirect, url_for
app = Flask(__name__)

@app.route("/")
def root():
    return "<h1>Hello!</h1>"
@app.route("/<user>")
def home(user):
    return f"Welcome to your home, <h1>{user}!</h1>"

if __name__ == "__main__":
    app.run(debug=True)