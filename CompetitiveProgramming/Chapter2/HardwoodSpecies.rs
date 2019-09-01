use std::io;
#[allow(unused_imports)]
use std::str;
#[allow(unused_imports)]
use std::collections::BTreeMap;

// Next step is to read input as integer

fn main()
{
    let mut input = String::new();
    match io::stdin()
        .read_line(&mut input)
        .expect("Failed to read from stdin");
    {
        Ok(n) => {
            println!("{} bytes read", n);
            println!("{}", input);
        }
        Err(error) => println!("error: {}", error),
    }

}
