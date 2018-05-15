let extractCategories: string => array(string) = [%bs.raw
  {|
    function (text) {
      return (text.match(/\[.*?\]/ig) || []).map(category => category.slice(1, -1))
    }
  |}
];

let extractCategories': string => array(string) =
  text =>
    text
    |> Js.String.split("\n")
    |> Js.Array.filter(line => Js.Re.test(line, [%re "/\\[.*?\\]/ig"]));

type subcategory = {
  .
  "name": string,
  "resources": array(string),
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

        current.resources = [line.slice(2), ...current.resources];
        return [current, ...other];
      }
      return categories;
    }, [])
  }
  |}
];