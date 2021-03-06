type category = {
  .
  "name": string,
  "path": string,
};

let extractCategories: string => array(category) = [%bs.raw
  {|
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
  |}
];

let extractCategories': string => array(string) =
  text =>
    text
    |> Js.String.split("\n")
    |> Js.Array.filter(line => Js.Re.test(line, [%re "/\\[.*?\\]/ig"]));

type resource = {
  .
  "title": string,
  "url": string,
};

type subcategory = {
  .
  "name": string,
  "resources": array(resource),
};

let extractSubCategories: string => array(subcategory) = [%bs.raw
  {|
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
  |}
];