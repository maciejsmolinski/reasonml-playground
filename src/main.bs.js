// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Document = require("./utils/document.bs.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var Application = require("./components/application.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function init() {
  Curry._1(Document.addReasonApplicationContainer, "reason-application");
  ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, Application.make(/* array */[])), "reason-application");
  return /* () */0;
}

exports.init = init;
/* Document Not a pure module */
