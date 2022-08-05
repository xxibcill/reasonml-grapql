module Styles = {
    open Css;

    let table =
        style([
            border(`px(1), `solid, Colors.dark),
            width(`percent(80.)),
            padding(`px(5))
        ]);
    let th = 
        style([
            border(`px(1), `solid, Colors.dark),
        ]);


};

open Types

[@react.component]
let make = (~data:array(blocks)) => {
    <table className=Styles.table>
        <thead >
            <tr>
                <th className=Styles.th>{"Height" |> React.string}</th>
                <th className=Styles.th>{"Hash" |> React.string}</th>
                <th className=Styles.th>{"TXN" |> React.string}</th>
                <th className=Styles.th>{"Timestamp" |> React.string}</th>
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
