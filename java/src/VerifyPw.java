import org.mindrot.jbcrypt.BCrypt;

public class VerifyPw {
	public static void main(String argv[]) {
		String pw = argv[0];
		String hash = argv[1];
		System.out.println(BCrypt.hashpw(pw, BCrypt.gensalt()));
		boolean matches = BCrypt.checkpw(pw, hash);
		if(matches) {
			System.out.println("Success, '" + pw + "' matches the hash: " + hash);
		} else {
			System.out.println("Oops, '" + pw + "' doesn't match the hash: " + hash);
		}
	}
}
