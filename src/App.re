module Styles = {
    open Css;

    let root =
        style([
            display(`flex),
            justifyContent(`center),
            alignItems(`center),
            width(`vw(100.)), 
            height(`vh(100.)), 
            backgroundColor(Colors.white),
            position(`relative)
        ]);
};

type person = {
    name:string,
    age: int
};

[@react.component]
let make = () => {
    let testRec = {
        name : "fred",
        age: 13
    };
    
    <div className=Styles.root>
        <div>
            { 
                switch(Js.Json.stringifyAny(testRec)){
                    | None => React.null
                    | Some(str) => str |> React.string 
                }
            }
        </div>
    </div>;
}