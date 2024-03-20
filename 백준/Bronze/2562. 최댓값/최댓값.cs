using System;

namespace boj2562
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[9];
            int max = 0;
            int num = 0;

            for (int i = 0; i < 9; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                    num = i+1;
                }
            }
            Console.WriteLine(max);
            Console.WriteLine(num);
        }
    }
}