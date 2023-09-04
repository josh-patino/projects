from flask import Flask, render_template

app = Flask(__name__)

# Define routes and views
@app.route('/')
def home():
    return render_template('index.html')

@app.route('/about')
def about():
    return 'This is the about page.'

@app.route('/contact')
def contact():
    return 'This is the contact page.'

if __name__ == '__main__':
    app.run(debug=True)

