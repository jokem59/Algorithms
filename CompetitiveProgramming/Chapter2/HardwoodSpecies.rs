use std::io;
#[allow(unused_imports)]
use std::str;
#[allow(unused_imports)]
use std::collections::BTreeMap;

// Next step is to read input as integer

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input);
    let numCases: i32 = input.parse::<i32>().unwrap();

    for _i in 0..numCases {
        let mut treeMap = BTreeMap::new();
        let mut total: f32 = 0.0;

        loop {
            io::stdin().read_line(&mut input);
            if input.len() == 0 { break; }

            if !treeMap.contains_key(&input) {
                treeMap.insert(&input, 1);
            }
            else {
                if let Some(count) = treeMap.get_mut(&input) {
                    *count += 1;
                }
            }
            total += 1.0;
        }

        for (key, val) in &treeMap {
            println!("{} {}", key, (*val as f32) / total * 100.0);
        }
    }
}
