module Styles = {
    open Css;

    let root =
        style([
            display(`flex),
            justifyContent(`center),
            alignItems(`center),
            width(`vw(100.)), 
            height(`vh(100.)), 
            backgroundColor(Colors.primary),
            position(`relative)
        ]);
};

[@react.component]
let make = () => {
    <div className=Styles.root>
        <h1>{"Hello World" |> React.string}</h1>
    </div>;
}