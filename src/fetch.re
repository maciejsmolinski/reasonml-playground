%bs.raw
{|
    var fetch = this.fetch;

    if (!fetch) {
        fetch = function () {
            return Promise.resolve({
                text: () => {
                    return Promise.resolve("dummy data");
                }
            });
        };
        this.fetch = fetch;
    }
|};

[@bs.val] external fetch : string => Js.Promise.t('a) = "fetch";

fetch("https://cdn.rawgit.com/maciejsmolinski/learnings/master/README.md")
|> Js.Promise.then_(v => Js.Promise.resolve(v##text()))
|> Js.Promise.then_(v => Js.Promise.resolve(Js.log(v)));