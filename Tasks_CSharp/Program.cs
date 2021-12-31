using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgotythmTasks_CSharp
{
    class Tasks
    {
        public static void task1()
        {
            StreamReader sr = new StreamReader("../../../INPUT.txt");
            StreamWriter sw = new StreamWriter("../../../OUTPUT.txt", false);//, System.Text.Encoding.Default);
            string input = sr.ReadLine();
            string[] s_numbers = input.Split(' ');
            int sum = 0;
            foreach (var s_number in s_numbers)
            {
                sum += Convert.ToInt32(s_number);
            }
            sw.WriteLine(sum.ToString());
            sw.Close();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Tasks.task1();            
        }
    }
}
