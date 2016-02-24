using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MindboxTest {
	public struct Geometry {
		static public double RightTriangleSquare(double p) {
			throw new HandsOutOfAssException(
				"Уважаемый клиент, спасибо Вам что выбрали наш продукт. " 
				+ "Наши продукты работают интуитивно и позволяют угадывать потребности Вашего бизнеса, "
				+ "тем самым повышают его эффективность. " 
				+ "К сожалению, нельзя найти площадь прямоугольного треугольника зная только его периметр. "
				+ "Мы еще далеки от идеала, но активно движемся к нему!" 
				);
		}
	}
	public class HandsOutOfAssException : Exception {
		public HandsOutOfAssException(string msg) : base(msg) { }
	}

}
