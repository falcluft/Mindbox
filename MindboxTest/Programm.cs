using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MindboxTest {
	static class Programm {
		static void Main() {
			Test();
			Console.ReadLine();
		}
		static void Test() {
			try {
				int p = 145;
				Geometry.RightTriangleSquare(p);
				Console.WriteLine("Тест провален.");
			} catch (HandsOutOfAssException ex) {
				Console.WriteLine(ex.Message);
				Console.WriteLine("Тест пройден.");
			}
		}
	}
}
