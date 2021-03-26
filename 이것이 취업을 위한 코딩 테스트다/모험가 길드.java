import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int n;
    public static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public static Queue<Integer> q = new LinkedList<>();
    public static Integer[] fear;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        fear = new Integer[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            fear[i] = x;
        }
        Arrays.sort(fear, Collections.reverseOrder());
        boolean flag = false;
        int num = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!flag) {
                num = fear[i] - 1;
                flag = true;
                cnt++;
            } else {
                if (num == 0) {
                    flag = false;
                    continue;
                }
                num--;
            }
        }
        System.out.println(cnt);
        br.close();
    }
}