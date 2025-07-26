import java.util.ArrayList;

public class Post {

    protected int likes;
    protected int id;
    protected long timestamp;
    protected boolean visibility; //Private(False) or Public(True)
    protected String comments;
    protected String author;
    protected ArrayList<Post> posts;

    //Post Constructor
    public Post(int p_id, boolean p_visiblity, String p_comments, String p_author) {
        this.likes = 0;
        this.id = p_id;
        this.timestamp = System.currentTimeMillis();
        this.visibility = p_visiblity;
        this.comments = p_comments;
        this.author = p_author;

        this.posts = new ArrayList<>();
    }

    //Methods
    public int getLikes() {
        return likes;
    }

    public int getId() {
        return id;
    }

    public long getTimeSincePosted() {
        long atual_time = System.currentTimeMillis();
        long posted_time = (atual_time - timestamp) / 1000; //converte os milisegundos para segundos (1s = 1000ms)

        return posted_time;
    }

    public boolean getVisibility() {
        return visibility;
    }

    public String getComments() {
        return comments;
    }

    public String getAuthor() {
        return author;
    }

    public void setLike() {
        this.likes += 1;
    }

    public void setUnlike() {
        if (likes > 0) {
            this.likes -= 1;
        } else {
            System.out.println("Tente Novamente!");
        }
    }

    public void setVisibility(String p_visibility) {
        if (p_visibility.equalsIgnoreCase("publico")) {
            this.visibility = true;
        } else if (p_visibility.equalsIgnoreCase("privado")) {
            this.visibility = false;
        } else {
            System.out.println("Opcao Invalida");
        }
    }

    public void addPost(Post current_post) {
        posts.add(current_post);
    }

    public void showPost(Post current_post) {

        if (current_post.getVisibility() == true) {
		System.out.println("Autor: " +current_post.getAuthor());
		System.out.println("Likes: " +current_post.getLikes());
		System.out.println("Comentarios: " +current_post.getComments());
		System.out.println("Postado a " +current_post.getTimeSincePosted() +" segundos");

        } else {
            System.out.println("O Post e privado");
        }
    }
}