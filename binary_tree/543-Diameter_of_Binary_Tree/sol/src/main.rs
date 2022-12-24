// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::rc::Rc;
struct Solution;
impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut diameter: i32 = 0;
        Solution::dfs(&root, &mut diameter);
        return diameter;
    }
    pub fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, diameter: &mut i32) -> i32 {
        match root {
            Some(root) => {
                let root = root.borrow();
                let left: i32 = Solution::dfs(&root.left, diameter);
                let right: i32 = Solution::dfs(&root.right, diameter);
                *diameter = std::cmp::max(*diameter, left + right);
                std::cmp::max(left, right) + 1
            }
            None => {
                return 0;
            }
        }
    }
}
fn main() {
    let a = Some(Rc::new(RefCell::new(TreeNode::new(1))));
    let b = Some(Rc::new(RefCell::new(TreeNode::new(2))));
    let c = Rc::clone(a.as_ref().unwrap());
    let d = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    let e = Some(Rc::new(RefCell::new(TreeNode::new(4))));
    let f = Some(Rc::new(RefCell::new(TreeNode::new(5))));
    c.as_ref().borrow_mut().left = b;
    c.as_ref().borrow_mut().right = d;
    let c = &c.as_ref().borrow().left;
    let c = c.as_ref().unwrap();
    c.as_ref().borrow_mut().left = e;
    c.as_ref().borrow_mut().right = f;
    // println!("{:?}",c);
    // println!("{:?}",a);

    let output = Solution::diameter_of_binary_tree(Some(Rc::clone(&a.as_ref().unwrap())));
    println!("{}",output);
}
