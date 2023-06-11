from flask import Flask, url_for, template_rendered, redirect
app = Flask(__name__)

@app.route("/")
def root():
    return "Hello!"

if __name__ == "__main__":
    app.run(debug=True)