import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int n;
    public static List<Integer> arr = new ArrayList<>();
    public static List<Integer> input = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++)
            input.add(Integer.parseInt(st.nextToken()));

        arr.add(input.get(n - 1));
        for (int i = n - 2; i >= 0; i--) {
            int now = input.get(i);
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