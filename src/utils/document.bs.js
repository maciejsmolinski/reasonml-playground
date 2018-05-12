// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

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

exports.clear = clear;
exports.append = append;
exports.addUniqueElement = addUniqueElement;
/* clear Not a pure module */