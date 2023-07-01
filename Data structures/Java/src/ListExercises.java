import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
public class ListExercises {
  private static int sum(List<Integer> lst) { // * returns the total sum of the elements in list.
    int ans = 0;
    for (int elem : lst) ans += elem;
    return ans;
  }
  private static List<Integer> even(List<Integer> lst) { // * return a new list containing the even number of given list.
    List<Integer> lst2 = new ArrayList<>();
    for (int elem : lst) if (!((elem & 1) != 0)) lst2.add(elem);
    return lst2;
  }
  private static List<Integer> common(List<Integer> lst, List<Integer> lst2) { // * return a new list contaning the common number of given two lists.
    List<Integer> lst3 = new ArrayList<>();
    for (int item : lst) if (lst2.contains(item)) lst3.add(item);
    return lst3;
  }
  public static void main(String[] args) {
    List<Integer> lst = new ArrayList<>();
    for (int i = 0; i < 9; ++i) lst.add(i);
    int cnt = sum(lst);
    List<Integer> lst2 = even(lst);
    System.out.println(lst2);
    System.out.println(cnt);
    List<Integer> lst3 = common(lst, lst2);
    System.out.println(lst3);
    return ;
  }
}
