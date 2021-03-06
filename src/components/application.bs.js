// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Api = require("../utils/api.bs.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Categories = require("./categories.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Subcategories = require("./subcategories.bs.js");

var component = ReasonReact.reducerComponent("Application");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (_self) {
              Curry._1(_self[/* send */3], /* Category */Block.__(0, [/* Load */0]));
              Api.getCategories(/* () */0).then((function (categories) {
                        return Promise.resolve(Curry._1(_self[/* send */3], /* Category */Block.__(0, [/* Update */[categories]])));
                      })).catch((function () {
                      return Promise.resolve(Curry._1(_self[/* send */3], /* Category */Block.__(0, [/* Failed */1])));
                    }));
              return /* () */0;
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              var onSelected = function (category) {
                Curry._1(_self[/* send */3], /* Subcategory */Block.__(1, [/* Load */0]));
                Api.getCategory(category).then((function (data) {
                        console.log(category, data);
                        Curry._1(_self[/* send */3], /* Subcategory */Block.__(1, [/* Update */[data]]));
                        return Promise.resolve(data);
                      }));
                return /* () */0;
              };
              var match = _self[/* state */1][/* subcategories */1];
              var tmp;
              tmp = typeof match === "number" ? (
                  match === 0 ? null : "Loading subcategories..."
                ) : (
                  match.tag ? ReasonReact.element(/* None */0, /* None */0, Subcategories.make(match[0], /* array */[])) : match[0]
                );
              var match$1 = _self[/* state */1][/* categories */0];
              var tmp$1;
              tmp$1 = typeof match$1 === "number" ? (
                  match$1 === 0 ? React.createElement("div", undefined, "...") : "Loading categories..."
                ) : (
                  match$1.tag ? ReasonReact.element(/* None */0, /* None */0, Categories.make(match$1[0], onSelected, /* array */[])) : match$1[0]
                );
              return React.createElement("div", {
                          className: "section has-background-white-bis"
                        }, React.createElement("div", {
                              className: "container"
                            }, React.createElement("div", {
                                  className: "columns"
                                }, React.createElement("div", {
                                      className: "column"
                                    }, tmp), React.createElement("div", {
                                      className: "column is-one-third"
                                    }, tmp$1))));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* categories : NotAsked */0,
                      /* subcategories : NotAsked */0
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                var a = action[0];
                if (typeof a === "number") {
                  if (a !== 0) {
                    return /* Update */Block.__(0, [/* record */[
                                /* categories */state[/* categories */0],
                                /* subcategories : Failure */Block.__(0, ["Failed to load subcategories"])
                              ]]);
                  } else {
                    return /* Update */Block.__(0, [/* record */[
                                /* categories */state[/* categories */0],
                                /* subcategories : Loading */1
                              ]]);
                  }
                } else {
                  return /* Update */Block.__(0, [/* record */[
                              /* categories */state[/* categories */0],
                              /* subcategories : Success */Block.__(1, [a[0]])
                            ]]);
                }
              } else {
                var a$1 = action[0];
                if (typeof a$1 === "number") {
                  if (a$1 !== 0) {
                    return /* Update */Block.__(0, [/* record */[
                                /* categories : Failure */Block.__(0, ["Failed to load categories"]),
                                /* subcategories */state[/* subcategories */1]
                              ]]);
                  } else {
                    return /* Update */Block.__(0, [/* record */[
                                /* categories : Loading */1,
                                /* subcategories */state[/* subcategories */1]
                              ]]);
                  }
                } else {
                  return /* Update */Block.__(0, [/* record */[
                              /* categories : Success */Block.__(1, [a$1[0]]),
                              /* subcategories */state[/* subcategories */1]
                            ]]);
                }
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
