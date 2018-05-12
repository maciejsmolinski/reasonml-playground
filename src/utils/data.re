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