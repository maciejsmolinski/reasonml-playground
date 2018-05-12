let clear: unit => unit = [%bs.raw
  {|
  function () {
    document.body.innerHTML = '';
  }
|}
];

let append: string => unit = [%bs.raw
  {|
    function (content) {
      document.body.innerHTML += content;
    }
  |}
];

let addUniqueElement: string => unit =
  uniqueId => append({j|<div id="$uniqueId"></div>|j});