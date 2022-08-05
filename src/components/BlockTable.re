module Styles = {
    open Css;

    let table =
        style([
            width(`percent(80.)),
        ]);

};

open Types

[@react.component]
let make = (~data:array(blocks)) => {
    <table className=Styles.table>
        <thead>
            <tr>
                <th>{"Height" |> React.string}</th>
                <th>{"Hash" |> React.string}</th>
                <th>{"Timestamp" |> React.string}</th>
            </tr>
        </thead>
        <tbody>
            {
                data |> Js.Array.map((e:blocks) => <BlockRow 
                key=Belt.Int.toString(e.height) 
                hash=e.hash 
                height=e.height 
                timestamp=e.timestamp 
                txn=e.txn
                />) |> React.array
            }
        </tbody>
    </table>
}
