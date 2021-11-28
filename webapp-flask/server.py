#!/usr/bin/env python

import json
import flask
from flask import request
from flask.helpers import make_response
from flask.json import jsonify
from flask.wrappers import Response
import nltk
from nltk.tokenize import word_tokenize

app = flask.Flask(__name__)
#app.config["DEBUG"] = True

# {
#   "tokenized": []    
# }

indexes = {
    "index1" : [
        {
            "id": 1,
            "title": "Title for doc one",
        },
        {
            "id": 2,
            "title": "amazing title for doc two",
        },
        {
            "id": 3,
            "title": "document 3 header",
        }
    ],
    "testindex": [
        {
            "id": 1,
            "title": "test index title",
        }
    ]
}

@app.route("/api/v1/tokenize", methods=['GET'])
def tokenize():
    if 'query' not in request.args:
        return Response("Query not specified!", status=400)

    query = request.args['query']
    mode = 'whitespace'
    if 'mode' in request.args:
        mode = request.args['mode']

    result = {}
    if mode == 'whitespace':
        result['tokenized'] = query.split()
    elif mode == 'nltk':
        result['tokenized'] =  word_tokenize(query)
    else:
        return make_response("Invalid tokenization mode!", 400)
    
    return jsonify(result)

@app.route("/api/v1/<index>/lookup/<id>", methods=['GET'])
@app.route("/api/v1/<index>/lookup", methods=['GET', 'POST'])
def lookup(index, id=None):
    lookup = None
    if request.method == 'GET':
        # Prioritizes the id passed as path of the route
        if id is None:
            if 'id' not in request.args:
                return Response("Id not specified!", status=400)
            lookupid = int(request.args['id'])
        else:
            lookupid = int(id)
    if request.method == 'POST':
        jsonbody = request.json
        if jsonbody is None or 'id' not in jsonbody:
            return Response("Id not specified!", status=400)
        lookupid = int(jsonbody['id'])

    if index not in indexes:
        return make_response(f'Index {index} not found!', 400)
    docs = indexes[index]

    res = None
    for doc in docs:
        if doc['id'] == lookupid:
            res = doc
            break
    if res is None:
        return make_response(f'No document with id {lookupid} found in index {index}')

    return jsonify(doc)
    #return jsonify(index = index, id = id)

def main():
    # Hostname and port can be changed while running the flask cmd
    app.run(host="localhost", port=5010)


if __name__=="__main__":
    main()


## Notes

# [--] Change port of flask web app
# Dynamic routing with resource names or api-version
# Create error response