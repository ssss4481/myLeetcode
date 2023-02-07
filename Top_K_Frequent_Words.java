import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.List;

public class Top_K_Frequent_Words
{
    public static void main(String[] args)
    {
        String[] words = {"i","love","leetcode","i","love","coding"};
        int k = 2;
        new Solution().topKFrequent(words, k);
    }
}

class Solution {
    public List<String> topKFrequent(String[] words, int k)
    {
        Map<String, Integer> count_table = new HashMap<>();

        for(var word : words)
        {
            var ret = count_table.putIfAbsent(word, 1);
            //System.out.printf("%s %d%n", word, ret==null ? 0:ret);
            if(ret != null)
            {
                count_table.replace(word, count_table.get(word)+1);
            }
        }
        //System.out.println("");

        ArrayList<Word> list = new ArrayList<>();

        for(Map.Entry<String, Integer> set : count_table.entrySet())
        {
            //System.out.printf("%s %d%n", set.getKey(), set.getValue());
            var input = new Word(set.getKey(), set.getValue());
            list.add(input);
        }

        Collections.sort(list, Collections.reverseOrder());

        ArrayList<String>ret = new ArrayList<>();

        for(int i = 0; i < k; ++i)
        {
            ret.add(list.get(i).getContent());
        }

        return (List<String>) ret;
    }



}

class  Word implements Comparable<Word>
{
    private String content;
    private Integer count;

    Word(String content, Integer count)
    {
        this.content = content;
        this.count = count;
    }

    public String getContent()
    {
        return this.content;
    }

    public Integer getCount()
    {
        return count;
    }

    @Override
    public int compareTo(Word w)
    {
        var countCmp = this.getCount().compareTo(w.getCount());
        if(countCmp != 0)
        {
            return countCmp;
        }
        return w.getContent().compareTo(this.getContent());
    }
}