let addReasonApplicationContainer: string => unit = [%bs.raw
  {|
      function (uniqueId) {
        var container;

        if (container = document.getElementById(uniqueId)) {
          container.remove();
        }

        container = document.createElement('div');
        container.id = uniqueId;
        document.body.appendChild(container);
      }
  |}
];