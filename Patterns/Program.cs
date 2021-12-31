using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lib;
namespace Patterns
{
    class Program
    {
        static void Main(string[] args)
        {
            Form form = new Form();
            Window window = new Window(form);
            window.Method_window();
        }
    }

    class Form : IMethodForm
    {
        public void Method_Form()
        {
            Console.WriteLine("method from Form");
        }
    }
  
}
