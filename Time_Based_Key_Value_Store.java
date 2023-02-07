import java.util.ArrayList;
import java.util.HashMap;

public class Time_Based_Key_Value_Store
{
    public static void main()
    {
        System.out.println(0);
    }

}

class TimeMap {
    private HashMap<String, ArrayList<Integer> > keyTimeStampRecord;
    private HashMap<String, ArrayList<String> > keyValueRecord;

    public TimeMap() {
        this.keyTimeStampRecord = new HashMap<>();
        this.keyValueRecord = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        if(!this.keyValueRecord.containsKey(key))
            keyInit(key, value, timestamp);
        else
            valueAppend(key, value, timestamp);
    }

    public String get(String key, int timestamp) {
        if(!this.keyValueRecord.containsKey(key))
            return "";

        return getLowerBound(key, timestamp);
    }


    private void keyInit(String key, String value, int timestamp) {
        ArrayList<String> valueArr = new ArrayList<>();
        valueArr.add(value);
        this.keyValueRecord.put(key, valueArr);

        ArrayList<Integer> timeArr = new ArrayList<>();
        timeArr.add(timestamp);
        this.keyTimeStampRecord.put(key, timeArr);
    }


    private void valueAppend(String key, String value, int timestamp) {
        ArrayList<String> valueArr = this.keyValueRecord.get(key);
        valueArr.add(value);

        ArrayList<Integer> timeArr = this.keyTimeStampRecord.get(key);
        timeArr.add(timestamp);
    }


    private String getLowerBound(String key, int timestamp){
        ArrayList<Integer> timeArr = this.keyTimeStampRecord.get(key);
        ArrayList<String> valueArr = this.keyValueRecord.get(key);
        if(timeArr.size() > 0){
            int idx = binarySearch(timeArr, timestamp, 0, (int)timeArr.size() - 1);
            if(idx >= 0)
                return valueArr.get(idx);
        }
        return "";
    }

    private int binarySearch(ArrayList<Integer> timeArr, int timestamp, int lo, int hi){
        int mid = (lo + hi)/2;

        if(lo == mid)
        {
            if(timeArr.get(hi) <= timestamp)
                return hi;
            else if(timeArr.get(lo) <= timestamp)
                return lo;
            else
                return -1;
        }

        if(timeArr.get(mid) < timestamp)
            return binarySearch(timeArr, timestamp, mid, hi);
        else if (timeArr.get(mid) == timestamp)
            return mid;
        else
            return binarySearch(timeArr, timestamp, lo, mid);
    }
}





/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */