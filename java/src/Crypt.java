import org.mindrot.jbcrypt.BCrypt;

public class Crypt {
	public static void main(String argv[]) {
		String pw = argv[0];
		System.out.println("clear text: " + pw);
		System.out.println("	Hashed: " + BCrypt.hashpw(pw, BCrypt.gensalt()));
	}
}
