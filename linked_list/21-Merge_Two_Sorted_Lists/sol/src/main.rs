// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
fn main() {
    let arr1: [i32;3] = [1,3,4];
    let mut list1: Box<ListNode> = Box::new(ListNode::new(arr1[0]));
    println!("{:?}",*list1);
    for i in 1..arr1.len() {
        let temp: ListNode = ListNode::new(arr1[i]);
        (*list1).next = Some(Box::new(temp));
        match list1.next {
            Some(x) => {list1 = x},
            None => println!("List1->next is null")
        }
        println!("{:?}",*list1);
    }
}
