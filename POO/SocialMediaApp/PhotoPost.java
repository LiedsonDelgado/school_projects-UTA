import java.util.ArrayList;

public class PhotoPost extends Post{
    protected String file; //file name and extension as a String f.ex: mountains.png
    protected String path;
    protected String description;
    protected String location;
    protected ArrayList<Post> listPP;//Posts feitos Photo Post

    //PhotoPost Constructor
    public PhotoPost(int p_id,boolean p_visiblity,String p_comments,String p_author,String p_file,String p_path,String p_description,String p_location){
        super(p_id, p_visiblity, p_comments, p_author);
        this.file = p_file;
        this.path = p_path;
        this.description = p_description;
        this.location = p_location;

        this.listPP = new ArrayList<>();
    }

    //Methods
    @Override
    public int getLikes(){
        return likes;
    }
    @Override
    public int getId(){
        return id;
    }
    @Override
    public long getTimeSincePosted(){
        return timestamp;
    }
    @Override
    public boolean getVisibility(){
        return visibility;
    }
    @Override
    public String getComments(){
        return comments;
    }
    @Override
    public String getAuthor(){
        return author;
    }

    public String getFile(){
        return file;
    }

    public String getPath(){
        return path;
    }

    public String getDescription(){
        return description;
    }

    public String getLocation(){
        return location;
    }

    public void setFile(String p_file){
        this.file = p_file;
    }

    public void setPath(String p_path){
        this.path = p_path;
    }

    public void setDescription(String p_description){
        this.description = p_description;
    }

    public void setLocation(String p_location){
        this.location = p_location;
    }   

    public void createPhotoPost(Post newPP){ //creates a new object Photo Post
        newPP = new Post(id, visibility, comments, author);
        listPP.add(newPP);
    }
}