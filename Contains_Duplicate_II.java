import java.util.*;





public class Contains_Duplicate_II
{
    public static void main(String[] args) {
        HashMap<Integer, Integer>  myMap = new HashMap<>();
        myMap.put(0, 0);
        Integer value = myMap.get(0);
        value += 1;
        System.out.println(value);
        System.out.println(myMap.get(0));



    }






}

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; ++i)
        {
            if(set.add(nums[i]) == false)
            {
                return true;
            }
            if(set.size() > k)
            {
                set.remove(nums[i-k]);
            }
        }
        return false;
    }
}


class Solution2 {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer>  myMap = new HashMap<>();
        Queue<Integer> Q = new LinkedList<>();

        if(k == 0)
        {
            return false;
        }

        for(int num: nums)
        {

            if(myMap.containsKey(num) && myMap.get(num) >= 1)
            {
                return true;
            }

            if(Q.size() == k)
            {
                Integer removeNum = Q.poll();
                Integer value = myMap.get(removeNum);
                myMap.replace(removeNum, value-1);
            }

            Q.add(num);

            if(myMap.containsKey(num))
            {
                Integer value =  myMap.get(num);
                myMap.replace(num, value+1);
            }
            else
            {
                myMap.put(num, 1);
            }
        }
        return false;
    }
}