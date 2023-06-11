from flask import Flask, jsonify, url_for, render_template, request
import threading
import time
import os.path
app = Flask(__name__, static_url_path='')

# https://www.geeksforgeeks.org/writing-files-background-python/
# Inheriting the base class 'Thread'
class AsyncWrite(threading.Thread):
    def __init__(self, text, out):
        # calling superclass init
        threading.Thread.__init__(self)
        self.text = text
        self.out = out
    def run(self):
        f = open(self.out, "a")
        f.write(self.text + '\n')
        f.close()
        # waiting for 2 seconds after writing
        # the file
        time.sleep(2)
        print("Finished background file write to", self.out)

@app.route('/')
def hello_world():
    return 'Welcome to my Home Page!'

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

# @app.route('/ans/<string:out>')
# def out_put(out):
#     f = open('B_Call_the_ID_Number.cpp', 'r')
#     out = f.read()
#     return out
@app.route('/<path:path>')
def static_file(path):
    return app.send_static_file(path)
@app.route('/answer/')
def hello():
    return app.send_static_file('B_Call_the_ID_Number.cpp')

# with app.test_request_context():
#     print(url_for('index'))
#     print(url_for('login'))
#     print(url_for('login', next='/'))
#     print(url_for('profile', username='John Doe'))


# query
# def read_file():
    # result = {
    #     "Number": False,
    #     "YourInput": out,
    #     "Status": "Okay!"
    # }
    # return out # jsonify(result)

# def Main():
#     message = read_file()
#     out_put(message)
#     background = AsyncWrite(message, 'out.cpp')
#     background.start()


    # print("The program can continue while it writes")
    # print("in another thread")
    # print("100 + 400 = ", 100 + 400)
 
    # wait till the background thread is done
    # background.join()
    # print("Waited until thread was complete")


if __name__ == "__main__":
    app.run(debug = True)
    # print(read_file())
    # Main()