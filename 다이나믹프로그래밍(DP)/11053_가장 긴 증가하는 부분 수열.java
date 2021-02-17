import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int n;
    public static List<Integer> arr = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr.add(Integer.parseInt(st.nextToken()));
        for (int i = 1; i < n; i++) {

            int now = Integer.parseInt(st.nextToken());
            int index = Collections.binarySearch(arr, now);
            if (arr.get(arr.size() - 1) < now) {
                arr.add(now);
            } else {
                if (index >= 0)
                    continue;
                arr.set(Math.abs(index) - 1, now);
            }
        }
        System.out.println(arr.size());
        br.close();
    }
}