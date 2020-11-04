public class FindTheNumber {
    public static void main(String[] args) {
        int[] rg = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 22, 23, 24, 25, 26, 27, 28,
                29, 30, 31 };

        Long n = 16L * 27L * 25L * 7L * 11L * 13L * 17L * 19L * 23L * 29L * 31L;
        n /= 34L;

        for (Long i = n; i < n + 1; i++) {
            int hit = 0;
            int hit1 = -1;
            int hit2 = -1;
            for (int j = 0; (j < 30) && (hit <= 2); j++) {
                if (i % rg[j] != 0) {
                    hit++;
                    if (hit == 1)
                        hit1 = j;
                    else if (hit == 2)
                        hit2 = j;
                    else
                        break;
                }
            }
            // System.out.println(String.format("i: %d, hit: %d, hit1: %d, hit2: %d", i,
            // hit, hit1==-1?-1:rg[hit1], hit2==-1?-1:rg[hit2]));
            if (hit == 2 && hit1 + 1 == hit2) {
                System.out.println(i);
            }
        }
    }
}