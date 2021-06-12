import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static int n, m;
    public static ArrayList<Integer> arr, lis;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new ArrayList<>();
        lis = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }
        Collections.reverse(arr);
        lis.add(arr.get(0));
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (lis.get(res) < arr.get(i)) {
                lis.add(arr.get(i));
                res++;
            } else {
                int bi = Collections.binarySearch(lis, arr.get(i));
                if (Math.abs(bi) - 1 >= lis.size() || Math.abs(bi) - 1 < 0)
                    continue;
                lis.set(Math.abs(bi) - 1, arr.get(i));
            }
        }
        System.out.println(n - (res + 1));
        br.close();
    }
}
