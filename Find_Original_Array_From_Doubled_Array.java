import java.util.*;

public class Find_Original_Array_From_Doubled_Array {
    public static void main(String[] args)
    {
        Solution obj = new Solution();
        int[] arr = {1, 3, 4, 2, 6, 8};
        int[] ret = obj.findOriginalArray(arr);
        
        for(int num: ret)
            System.out.println(num);
    }
    
}

class Solution 
{

    public int[] findOriginalArray(int[] changed) 
    {        
        int[] temp = new int[changed.length/2];
        int[] empty = {};
        
        if(changed.length%2 == 1)
            return empty;

        Queue<Integer> q = new LinkedList<>();

        Arrays.sort(changed);

        int idx = 0;

        for(int num: changed)
        {
            if(q.isEmpty() || num !=  q.peek())
            {
                q.add(2*num);
            }
            else
            {
                temp[idx] = q.poll()/2;
                idx++;
            }
        }

        if(q.isEmpty())
            return temp;

        return empty;
    }

}

class Solution2 {

    public int[] findOriginalArray(int[] changed) 
    {
        int[] empty = {};
        int[] ret = new int[changed.length/2];
        if(changed.length % 2 == 1)
        {
            return empty;
        }
        
        
        TreeMap<Integer, Integer> recordMap = new TreeMap<Integer, Integer>();

        for(var num : changed)
        {
            if(recordMap.containsKey(num))
            {
                recordMap.replace(num, recordMap.get(num)+1);
            }
            else
            {
                recordMap.put(num, 1);
            }    
        }

        int idx = 0;
        System.out.println(recordMap.keySet());
        System.out.println(recordMap.values());

        for(Map.Entry<Integer, Integer> entry: recordMap.entrySet())
        {
            //System.out.println(entry.getKey());            
            var key = entry.getKey();
            var value = entry.getValue();
            //System.out.printf("Key: %d Value: %d %n", key, value);
            if(key == 0)
            {
                if(value %2 == 1)
                {
                    return empty;
                }
                else
                {
                    for(int i = 0; i < value/2; i++)
                    {
                        ret[idx] = key;  
                        idx++;    
                    }  
                }
                continue;
            }


            if(value == 0)
            {
                continue;
            }
            else if(recordMap.containsKey(2*key))
            {
                recordMap.replace(key*2, recordMap.get(key*2) - value);
            }
            else
            {
                return empty;
            }
            if(value >= 0 && idx + value -1 < changed.length/2)
            {               
                for(int i = 0; i < value; i++)
                {
                    ret[idx] = key;  
                    idx++;    
                }

            }
            else
            {
                return empty;
            }        
        }    

       return ret;

    }
}
