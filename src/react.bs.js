// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var clear = (
    function () {
      document.body.innerHTML = '';
    }
  );

var append = (
      function (content) {
        document.body.innerHTML += content;
      }
    );

function addUniqueElement(uniqueId) {
  return Curry._1(append, "<div id=\"" + (String(uniqueId) + "\"></div>"));
}

var Dom = /* module */[
  /* clear */clear,
  /* append */append,
  /* addUniqueElement */addUniqueElement
];

var extractCategories = (
    function (text) {
      return (text.match(/\[.*?\]/ig) || []).map(category => category.slice(1, -1))
    }
  );

var Data = /* module */[/* extractCategories */extractCategories];

var component = ReasonReact.statelessComponent("Category");

function make(name, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("span", {
                          className: "categories__item tag is-dark"
                        }, name);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var Category = /* module */[
  /* component */component,
  /* make */make
];

var component$1 = ReasonReact.statelessComponent("Categories");

function toCategory(name) {
  return ReasonReact.element(/* Some */[name], /* None */0, make(name, /* array */[]));
}

function make$1(data, _) {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */component$1[/* didMount */4],
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          className: "categories"
                        }, $$Array.map(toCategory, data));
            }),
          /* initialState */component$1[/* initialState */10],
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */component$1[/* reducer */12],
          /* subscriptions */component$1[/* subscriptions */13],
          /* jsElementWrapped */component$1[/* jsElementWrapped */14]
        ];
}

var Categories = /* module */[
  /* component */component$1,
  /* toCategory */toCategory,
  /* make */make$1
];

Curry._1(clear, /* () */0);

function renderApp(arr) {
  addUniqueElement("root");
  return ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, make$1(arr, /* array */[])), "root");
}

fetch("https://rawgit.com/maciejsmolinski/learnings/master/README.md").then((function (prim) {
          return prim.text();
        })).then((function (text) {
        return Promise.resolve(renderApp(Curry._1(extractCategories, text)));
      }));

exports.Dom = Dom;
exports.Data = Data;
exports.Category = Category;
exports.Categories = Categories;
exports.renderApp = renderApp;
/* clear Not a pure module */
