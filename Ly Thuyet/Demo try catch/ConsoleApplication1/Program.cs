using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int soluong;
sondeptrai:
            Console.Write("\nNhap vao so luong: ");
            try
            {
                soluong = int.Parse(Console.ReadLine());
            }
            catch
            {
                Console.Write("\nLoi kieu du lieu");
                goto sondeptrai;
            }
            

            Console.Write("\nSo luong = " + soluong);

            Console.ReadKey();
        }
    }
}
