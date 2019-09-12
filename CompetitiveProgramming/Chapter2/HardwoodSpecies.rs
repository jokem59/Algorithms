use std::io;
#[allow(unused_imports)]
use std::str;
#[allow(unused_imports)]
use std::collections::BTreeMap;

// Iteration 0: Below implementation returns the following
//
// error[E0502]: cannot borrow `input` as mutable because it is also borrowed as immutable
//   --> .\HardwoodSpecies.rs:19:35
//    |
// 19 |             io::stdin().read_line(&mut input);
//    |                                   ^^^^^^^^^^ mutable borrow occurs here
// ...
// 22 |             if !treeMap.contains_key(&input) {
//    |                 ------- immutable borrow later used here
// 23 |                 treeMap.insert(&input, 1);
//    |                                ------ immutable borrow occurs here

// error: aborting due to previous error

// For more information about this error, try `rustc --explain E0502`.

// fn main() {
//     let mut input = String::new();
//     io::stdin().read_line(&mut input);
//     let numCases: i32 = input.parse::<i32>().unwrap();

//     for _i in 0..numCases {
//         let mut treeMap = BTreeMap::new();
//         let mut total: f32 = 0.0;

//         loop {
//             io::stdin().read_line(&mut input);
//             if input.len() == 0 { break; }

//             if !treeMap.contains_key(&input) {
//                 treeMap.insert(&input, 1);
//             }
//             else {
//                 if let Some(count) = treeMap.get_mut(&input) {
//                     *count += 1;
//                 }
//             }
//             total += 1.0;
//         }

//         for (key, val) in &treeMap {
//             println!("{} {}", key, (*val as f32) / total * 100.0);
//         }
//     }
// }


// Iteration 1: Below implementaiton fixes the primary issue and conforms to snake case styling.
// the BTreeMap is using <&String, i32>, therefore, the tree_map is holding an immutable reference to input.  Then we try and get
// a mutable reference to input and Rust disallows this.  If this was allowed, we would be changing the key in the tree_map which breaks
// the invariant provided by BTreeMap: https://doc.rust-lang.org/std/collections/struct.BTreeMap.html
// "It is a logic error for a key to be modified in such a way that the key's ordering relative to any other key, as determined by the
// Ord trait, changes while it is in the map."
//
// Make comments on unwrap().

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num_cases: i32 = input.parse::<i32>().unwrap();

    for _i in 0..num_cases {
        let mut tree_map = BTreeMap::new();
        let mut total: f32 = 0.0;

        loop {
            io::stdin().read_line(&mut input).unwrap();
            if input.len() == 0 { break; }

            if !tree_map.contains_key(&input) {
                tree_map.insert(input.clone(), 1);
            }
            else {
                if let Some(count) = tree_map.get_mut(&input) {
                    *count += 1;
                }
            }
            total += 1.0;
        }

        for (key, val) in &tree_map {
            println!("{} {}", key, (*val as f32) / total * 100.0);
        }
    }
}
