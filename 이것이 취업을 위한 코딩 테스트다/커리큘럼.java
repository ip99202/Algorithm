import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int n;
    public static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public static Queue<Integer> q = new LinkedList<>();
    public static int[] time, indegree, origin;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        time = new int[n + 1];
        origin = new int[n + 1];
        indegree = new int[n + 1];

        for (int i = 0; i <= n; i++)
            arr.add(new ArrayList<Integer>());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            time[i] = x;
            origin[i] = x;
            while (true) {
                int a = Integer.parseInt(st.nextToken());
                if (a == -1)
                    break;
                arr.get(a).add(i);
                indegree[i]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        int res = 0;
        while (!q.isEmpty()) {
            int now = q.poll();
            for (int i = 0; i < arr.get(now).size(); i++) {
                int next = arr.get(now).get(i);
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.add(next);
                    time[next] += time[now];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(time[i]);
        }
        br.close();
    }
}