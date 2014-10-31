import java.util.HashMap;
import java.util.Map;

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class ReorderList {
	public void reorderList(ListNode head) {
		int count = 0;
		Map<Integer, ListNode> map = new HashMap<Integer, ListNode>();
		while (head != null) {
			map.put(count ++, head);
			head = head.next;
		}
		ListNode ans = new ListNode(0);
		ListNode tmp = ans;
		for (int i = 0; i < count/2; i ++) {
			tmp.next = map.get(i);
			if (count - i > 0) {
				tmp.next.next = map.get(count - 1 - i);
				tmp = tmp.next.next;
				if (tmp.next != null && tmp != null)
					tmp.next = null;
			}
		}
		if (count != 1 && (count % 2) != 0) {
			tmp.next = map.get(count/2);
			tmp.next.next = null;
		}
		head = ans.next;
		while (head != null) {
			System.out.println(head.val);
			head = head.next;
		}
	}
	public static void main(String[] args) {
		ListNode l0 = new ListNode(0);
		ListNode l1 = new ListNode(1);
		ListNode l2 = new ListNode(2);
		ListNode l3 = new ListNode(3);
		ListNode l4 = new ListNode(4);
		ListNode l5 = new ListNode(5);
		l0.next = l1;
		l1.next = l2;
		l2.next = l3;
		l3.next = l4;
//		l4.next = l5;
		ReorderList r = new ReorderList();
		r.reorderList(l0);
	}
}
