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

struct Solution;
impl Solution {
    // pub fn merge_two_lists(l1: Option<Box<ListNode>>,l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    //     let mut start: Box<ListNode> = Box::new(ListNode::new(0));
    //     let mut end = &mut start;
    //     let mut l1 = &l1;
    //     let mut l2 = &l2;
    //     while l1.is_some() && l2.is_some() {
    //         let n1 = l1.as_ref().unwrap();
    //         let n2 = l2.as_ref().unwrap();
    //     }
    //     start.next
    // }
    pub fn merge_two_lists(l1: Option<Box<ListNode>>,l2: Option<Box<ListNode>>) {
        let l1 = l1.unwrap();
        let l2 = l2.unwrap();
        println!("{:?}",l1.next);
        println!("{:?}",l2);
    }
}
fn main() {
    let arr1: [i32;3] = [1,3,4];
    let arr2: [i32;3] = [1,2,4];
    let mut head1: Box<ListNode> = Box::new(ListNode::new(0));
    let mut head2: Box<ListNode> = Box::new(ListNode::new(0));
    let mut list2 = &mut head2;
    let mut list1 = &mut head1;
    for i in 0..arr1.len() {
        let temp: ListNode = ListNode::new(arr1[i]);
        (*list1).next = Some(Box::new(temp));
        list1 = list1.next.as_mut().unwrap();
    }
    for i in 0..arr2.len() {
        let temp: ListNode = ListNode::new(arr2[i]);
        (*list2).next = Some(Box::new(temp));
        list2 = list2.next.as_mut().unwrap();
    }
    Solution::merge_two_lists(Some(head1), Some(head2));
}
