// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';


var extractCategories = (
    function (text) {
      return text.split("\n").reduce((categories, line) => {
        var name, path;
        if (line.startsWith("*")) {
          name = (line.match(/\[(.*?)\]/ig) || [''])[0].slice(1, -1);
          path = (line.match(/\((.*?)\)/ig) || [''])[0].slice(2, -4);
          return [{ name: name, path: path }, ...categories];
        }
        return categories;
      }, [])
    }
  );

function extractCategories$prime(text) {
  return text.split("\n").filter((function (line) {
                return (/\[.*?\]/ig).test(line);
              }));
}

var extractSubCategories = (
  function (text) {
    return text.split("\n").reduce((categories, line) => {
      if (line.startsWith("##")) {
        return [{ name: line.slice(3), resources: [] }, ...categories];
      }
      if (line.startsWith("*")) {
        let [current, ...other] = categories;

        current.resources = [ { title: line.slice(2), url: '' }, ...current.resources];
        return [current, ...other];
      }
      if (line.startsWith("  http")) {
        let [current, ...other] = categories;
        let [resource, ...resources] = current.resources;

        resource.url = line.slice(2);
        current.resources = [resource, ...resources];

        return [current, ...other]
      }
      return categories;
    }, [])
  }
  );

exports.extractCategories = extractCategories;
exports.extractCategories$prime = extractCategories$prime;
exports.extractSubCategories = extractSubCategories;
/* extractCategories Not a pure module */
